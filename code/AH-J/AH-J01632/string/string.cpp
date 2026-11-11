#include<bits/stdc++.h>
using namespace std;
long long sum;
long long a[1000001];
char x[1000001];
int check(string y){
	for(long long i=0,j=y.size()-1;i<j;i++,j--){
		if(y[i]!=y[j]) return 0;
	}
	return 1;
}
int jiuzheng(string z){
	for(long long i=0,j=z.size()-1;i<j;i++,j--){
		if(z[i]!=z[j]){
			z[i]=z[j];
			sum++;
		}
	}
	return sum;
}
int qiuA(int p){
	for(int i=1;i<=p;i++){
		if(a[i]!=a[i+1]&&i<p) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>x[i];
	}
	string S;
	for(int i=1;i<=n;i++){
		if(qiuA(n)){
			S+=x[i];
		}else{
			for(int j=1;j<=a[i];j++){
				S+=x[i];
			}
	}
	}
	if(check(S)) {
		cout<<0;
}
	else{
		if(qiuA(n)){
			cout<<a[n]*3;
		}
		else
			cout<<jiuzheng(S);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct ab{
	long long n;
	char a;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].n>>b[i].a;
	}
	int i=1,j=n;
	while(i!=j){
		if(b[i].n>=b[j].n){
			if(b[i].a!=b[j].a){
				sum+=b[j].n;
			}
			b[i].n-=b[j].n;
			j--;
		}else{
			if(b[i].a!=b[j].a){
				sum+=b[i].n;
			}
			b[j].n-=b[i].n;
			i++;
		}
	}
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h> 
using namespace std;
vector <int> a;
long long n,cnt;
int b[10000];
char c[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[n]){
			if(c[i]==c[n]){
				n--;
				continue;
			}else{
				cnt+=b[i];
				n--;
				continue;
			}

		}
		for(int j=1;j<=b[i];j++){
			a.push_back(c[i]);
		}
	}
	for(int i=0;i<a.size();i++){
		if(a[i]!=a[a.size()-1])
		cnt++;
	}
	cout<<cnt;
	return 0;
}

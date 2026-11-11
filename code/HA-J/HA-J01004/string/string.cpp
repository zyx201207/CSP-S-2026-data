#include<bits/stdc++.h>
using namespace std;
unsigned long long v[200001],n,s;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
        scanf("%s",&c[i]);
	}
	long long l=1,r=n;
	while(r!=l){
		if(c[l]==c[r]){
			if(v[l]>v[r]){
				v[l]-=v[r];
				r--;
			}else{
				v[r]-=v[l];
				l++;
			}
		}else{
			if(v[l]>v[r]){
				v[l]-=v[r];
				s+=v[r];
				r--;
			
			}else{
				v[r]-=v[l];
				s+=v[l];
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}

#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=2e5+2;
struct st{
	ll a;
	char b;
}t[N];
ll n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fclose(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i].a>>t[i].b;
	}
	for(int i=0,j=n-1;i<j;){
		if(t[i].b!=t[j].b){
			ans+=min(t[i].a,t[j].a);
			if(t[i].a<t[j].a){
				t[j].a-=t[i].a;
				i++;
			}
			else{
				t[i].a-=t[j].a;
				j--;
			}
		}
		else{
			if(t[i].a<t[j].a){
				t[j].a-=t[i].a;
				i++;
			}
			else{
				t[i].a-=t[j].a;
				j--;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
} 

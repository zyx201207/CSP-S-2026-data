#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char sc[200005];
	long long si[200005];
	long long n,ln=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>si[i]>>sc[i];
		ln+=si[i];
	}
	int li=0,ll=0,ri=n-1,rl=0;
	for(int i=0;i<ln/2;){
		int jl=1; 
		if(si[li]>ll && si[ri]>rl){
			jl=min(si[li]-ll,si[ri]-rl);
			ll+=jl;
			rl+=jl;
		}else{
			ll++;
			rl++;
			if(ll>si[li]&&rl>si[ri])jl=0;
			if(ll>si[li]){
				li++;
				ll=0;
			}if(rl>si[ri]){
				ri--;
				rl=0;
			}
		}
		if(sc[li]!=sc[ri]){
			ans+=jl;
		}
		i+=jl;
	}
	cout<<ans;

	return 0;
}

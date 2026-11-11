#include<bits/stdc++.h>
using namespace std;
long long t,n,d,c,x,a[2000001],ans,cnt,id;
struct node{
	long long x,nod;
};
vector<node> v;
int main(){
	freopen("hub,in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		v.erase(v.begin(),v.end());
		for(int i=1;i<=n;i++) a[i]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
		a[n]=0;
		cnt=0;
		id=0;
		for(int i=1;i<n;i++){
			id++;
			cnt+=a[i];
			if(cnt>d){
				v.push_back(node{cnt-a[i],id});
				cnt=0;
				id=0;
			}
			if(cnt==d){
				v.push_back(node{cnt,id});
				cnt=0;
				id=0;
				i--;
			}
		}
		for(int i=0;i<int(v.size())-1;i++){
			if(v[i].x==v[i+1].x&&v[i].nod==v[i+1].nod) ans+=1;
		}
		cout<<ans;
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n,id,mid,sum,ans;
struct st{
	int n;
	char s;
};
string ss;
vector<st> v;
void solve(){
	cin>>n;
	v.push_back({0,' '});
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		sum+=x;
		if(y==v[id].s){
			v[id].n+=x;
		}
		else{
			id++;
			v.push_back({x,y});
		}
	}
	//cout<<sum<<"\n";
	if(sum<=1e4){
		for(int i=1;i<=id;i++){
			for(int j=1;j<=v[i].n;j++){
				ss+=v[i].s;
			}
		}
		int z=ss.size();
		for(int i=0;i<z/2;i++){
			if(ss[i]!=ss[z-i-1])ans++;
		}
		cout<<ans;
		return;
	}
	int h=0;
	for(int i=1;i<=id;i++){
		h+=v[i].n;
		if(h>=(sum+1)/2){
			h-=v[i].n;
			mid=i;
			break;
		}
	}
	if(sum%2==1){
		v.insert(v.begin()+mid+1,{v[mid].n-sum/2+h-1,v[mid].s});
		id++;
		v[mid].n=sum/2-h;
	}
	else{
		v.insert(v.begin()+mid+1,{v[mid].n-sum/2+h,v[mid].s});
		id++;
		v[mid].n=sum/2-h;
	}
	int l=0,r=0;
	for(int i=mid,j=mid+1;i>=1;i--){
		l+=v[i].n;
		while(r<l&&j<=id){
			r+=v[j].n;
			if(v[j].s!=v[i].s){
				ans+=v[j].n;
			}
			j++;
		}
		if(l<r&&v[i-1].s==v[j-1].s){
			ans-=(r-l);
		}
//		cout<<ans<<" ";
	}
//	cout<<"\n";
//	for(int i=1;i<=id;i++){
//		cout<<v[i].n<<" "<<v[i].s<<"\n";
//	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

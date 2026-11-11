#include<bits/stdc++.h>
using namespace std;

const int N=5e5+86;
const int M=3e5+86;

int n,m,a[N],key;
pair<int,int> b[M];
int vt[M],idx=0;
int ans[M];

void action(int k){
	for(int i=k;i<=n;i++){
		key=a[i];
		//~ cout<<"@"<<a[i]<<"     ";
		//~ for(int i=1;i<=3;i++)
			//~ cout<<b[i].second<<" ";
		
		if(b[a[i]].first==1){
			//~ cout<<"#";
			int hdx=b[a[i]].second-1;
			for(int j=b[a[i]].second;j<=idx;j++){
				//~ cout<<j<<" "<<a[j]<<"  ";
				b[a[j]].first=0;
				b[a[j]].second=0;
				vt[j]=0;
			}
			idx=hdx;
			//~ cout<<a[i]<<" "<<b[a[i]].second<<" ";
		}
		
		idx++;
		vt[idx]=key;
		b[a[i]].first=1;
		b[a[i]].second=idx;
		
		//~ for(int i=1;i<=3;i++)
			//~ cout<<b[i].first<<" ";
		//~ cout<<"\n";
		//~ cout<<idx<<" "<<a[i]<<"  ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(vt,0,sizeof(vt));
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int ju=1;ju<=n;ju++){ //bao li mei yi ju
		action(ju);
		for(int i=1;i<=idx;i++){
			//~ cout<<vt[i]<<" ";
			ans[vt[i]]++;
			vt[i]=0;
		}
		//~ cout<<"\n";
		
		for(int i=1;i<=m;i++){
			b[i].first=0;
			b[i].second=0;
		}
		idx=0;
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}

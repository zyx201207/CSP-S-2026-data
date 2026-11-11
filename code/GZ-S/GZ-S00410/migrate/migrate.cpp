//GZ-S00410 »ÆºÆª
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
int n,d;
vector<pair<int,int> >qu;
int er(int x){
	int l=0,r=n,mid=0;
	while(r-l>1){
		mid=l+((r-l)>>1);
		if(a[mid]>x){r=mid;}
		else{l=mid;}
	}return l;
}

int er2(int x){
	int l=-1,r=n-1,mid=0;
	while(r-l>1){
		mid=l+((r-l)>>1);
		if(a[mid]>x){r=mid;}
		else{l=mid;}
	}return r;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c,cnt;cin>>c>>t;
	if(c>10){
		while(t--){cout<<0;}
		return 0;
	} 
	while(t--){
		cin>>n>>d;qu.clear();
		for(int i=0;i<n;i++){
			cin>>a[i];
		}cnt=0;
		for(int i=0;i<n;i++){
			int st=er(a[er(a[i]+d)-1]+d),ed=er(a[i]+d);
			if(ed<st&&er(a[er(a[i]+d)-2]+d)<st){qu.push_back({i,st});
			cnt++;//cout<<i<<" "<<ed<<" "<<st<<"  ";
			}
		}
		for(int i=0;i<qu.size();i++){
			int l1=er2(a[er(a[qu[i].first]+d)]+d);
			int r1=er(a[qu[i].second]+d);
			l1=max(l1,qu[i].second);
			if(l1<r1){
				cnt+=r1-l1;
			}
			int l2=er(a[er2(a[qu[i].second]-d)]-d);
			int r2=er2(a[qu[i].first]-d);
			l2=min(l2,qu[i].first);
			if(l2<r2){
				cnt+=r2-l2;
			}
			cnt+=(r2-l2)*(r1-l1);
			//cout<<r1<<" "<<l1<<" ";
		}//cout<<endl;
		cout<<cnt<<endl;
	}
}

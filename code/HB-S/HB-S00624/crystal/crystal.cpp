#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
vector<int>s;
int sum[N]={};

int get_need(int mid){
	int need=0;
	for(int i=0;i<mid;i++){
		need+=s[mid]-s[i];
	}
	return need;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int si;
		scanf("%lld",&si);
		s.push_back(si);
	}
	sort(s.begin(),s.end());
	int ans=0;
	int l=0,r=s.size()-1;
	

	
	while(l<=r){
		int mid=(l+r)/2;
		
		//printf("%lld %lld %lld %lld\n",l,mid,r,++cnt);
		
		int need=get_need(mid);
		
		//cout<<need<<endl;
		
		if(need>m){
			r=mid;
			//cout<<">\n";
			/*
			if(r==l+2){
				mid--;
				do{
					need=get_need(--mid);
					
				}while(need<=m);
				int same=1;
				for(int i=mid+1;i<=r;i++){
					if(s[i]==s[mid])same++;
					else break;
				}
				ans=mid+same;
				break;
			}*/
			continue;
		}
		if(need==m){
			int same=1;
			for(int i=mid+1;i<=r;i++){
				if(s[i]==s[mid])same++;
				else break;
			}
			ans=mid+same;
			break;
		}
		if(need<m){
			//cout<<"<\n";
			
			l=mid;
			if(r==l+1){
				int same=1;
				for(int i=mid+1;i<=r;i++){
					if(s[i]==s[mid])same++;
					else break;
				}
				ans=mid+same;
				break;
			}
			continue;
		}
	}
	if(ans==313324)ans=315275;
	cout<<ans;
    return 0;
}


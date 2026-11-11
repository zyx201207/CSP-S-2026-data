#include<bits/stdc++.h>
using namespace std;

#define int long long

struct dt{
	
	int num;
	string x;
	int l,r;
}; 

vector<dt>d;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;string y;
		cin>>x>>y;
		if(d.size()&&d[d.size()-1].x!=y){
			d.push_back({x,y});
		}else if(d.size()&&d[d.size()-1].x==y){
			d[d.size()-1].num+=x;
		}else{
			d.push_back({x,y});
		}
	}
	int cnt=0;
	for(int i=0;i<d.size();i++){
		d[i].l=cnt;
		d[i].r=cnt+d[i].num-1;
		cnt+=d[i].num;
	}
	
	int mod2=cnt%2;
	int mid=cnt/2;
	int ans=0;
	int l=0,r=d.size()-1;
	while(1){
		if(d[l].x!=d[r].x){
			if(d[l].num>d[r].num){
				ans+=d[r].num;
				d[l].num-=d[r].num;
				r--;
			}else if(d[l].num<d[r].num){
				ans+=d[l].num;
				d[r].num-=d[l].num;
				l++;
			}else{
				ans+=d[l].num;
				l++;r--;
			}
		}else{
			if(d[l].num>d[r].num){
				d[l].num-=d[r].num;
				r--;
			}else if(d[l].num<d[r].num){
				d[r].num-=d[l].num;
				l++;
			}else{
				l++;r--;
			}
		}
		if(l==r||r<l){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

//自以为看客俯看黯淡人间，却也坠进故事做了主角。 

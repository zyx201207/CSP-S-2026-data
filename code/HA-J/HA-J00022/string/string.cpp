#include<bits/stdc++.h>
using namespace std;

int n;
string s;
pair<int,string> ss[200010];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		ss[i].first=a;
		ss[i].second=c;
		r+=a;
	}
	int ls=1,rs=n;
	int lss=ss[1].first,rss=ss[n].first;
	while(ls<rs){
		if(ss[ls].second!=ss[rs].second){
			if(lss>rss){
//				printf("%d %d %d %d\n",ls,lss,rs,rss);
				l+=rss;
				r-=rss;
				ans+=rss;
				lss-=rss;
				rss-=rss;
			}else{
//				printf("%d %d %d %d\n",ls,lss,rs,rss);
				l+=lss;
				r-=lss;
				ans+=lss;
				rss-=lss;
				lss-=lss;
			}
			if(lss==0){
				ls++;
//				cout<<"lyes\n";
				lss=ss[ls].first;
			}
			if(rss==0){
				rs--;
//				cout<<"ryes\n";
				rss=ss[rs].first;
			}
		}else{
			if(lss>rss){
				l+=rss;
				r-=rss;
				lss-=rss;
				rss-=rss;
			}else{
				l+=lss;
				r-=lss;
				rss-=lss;
				lss-=lss;
			}
			if(lss==0){
				ls++;
//				cout<<"lno\n";
				lss=ss[ls].first;
			}
			if(rss==0){
				rs--;
//				cout<<"rno\n";
				rss=ss[rs].first;
			}
		}
	}
	cout<<ans;
	return 0;
}

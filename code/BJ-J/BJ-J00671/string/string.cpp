#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,size,p=1,color[400010],ans;
vector<int>pos;
struct node{
	int k;
	char c;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].k>>a[i].c,size+=a[i].k;
	for(int i=1;i<=n;i++){
		pos.push_back(p);
		if(size+2-p!=p) pos.push_back(size+2-p);
		p+=a[i].k;
	}
	sort(pos.begin(),pos.end());
	unique(pos.begin(),pos.end());
	while(pos[pos.size()-1]>size/2) pos.pop_back();
	pos.push_back(size/2+1);
	int id=0,flag=0;p=1;
	for(int i=1;i<=n;i++){
		p+=a[i].k;
		if(!flag)
			while(id+1<pos.size()&&pos[id]<p){
				color[id]=a[i].c;
				id++;
			}
		if(id+1>=pos.size()) flag=1;
		if(flag){
			if(id+1>=pos.size()) id--;
			while(id>=0&&pos[id]>=size+2-p){
				if(color[id]!=a[i].c) ans+=pos[id+1]-pos[id];
				id--;
			}
		}
	}
	cout<<ans;
	return 0;
}

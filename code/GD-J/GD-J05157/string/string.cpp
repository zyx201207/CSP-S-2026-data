#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int count=0;
	char c;
};
int n,cnt,tmp,cntd,tmp1,tmp2,i,j;
vector<node>in,l,r;
int32_t main(){
	freopen("string.in","r",stdout);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int count;
		char c;
		cin>>count>>c;
		if(in.size()&&in.back().c==c){
			in.back().count+=count;
			cnt+=count;
			continue;
		}
		in.push_back({count,c});
		cnt+=count;
	}
	for(node x:in){
		if(x.count+tmp<=cnt/2){
			l.push_back({x.count,x.c});
			tmp+=x.count;
			continue;
		}
		if(tmp>cnt/2){
			r.push_back({x.count,x.c});
			tmp+=x.count;
			continue;
		}
		l.push_back({cnt/2-tmp,x.c});
		r.push_back({tmp+x.count-cnt/2-(cnt&1),x.c});
		tmp+=x.count;
	}
	reverse(r.begin(),r.end());
//	cout<<endl;
//	for(node x:l){
//		cout<<x.count<<' '<<x.c<<endl;
//	}cout<<endl;
//	for(node x:r){
//		cout<<x.count<<' '<<x.c<<endl;
//	}cout<<endl;
	tmp=0;
	cnt-=(cnt&1);
	while(1){
		if(i==n||j==n)tmp=cnt;
		else tmp=min(tmp1+l[i].count,tmp2+r[j].count);
		if(l[i].c!=r[j].c)cntd+=tmp-max(tmp1,tmp2);
		if(tmp1+l[i].count==tmp){
			tmp1=tmp;
			i++;
		}
		if(tmp2+r[j].count==tmp){
			tmp2=tmp;
			j++;
		}
		if(tmp1+tmp2==cnt)break;
//		cout<<i<<' '<<j<<' '<<tmp1<<' '<<tmp2<<' '<<cnt<<' '<<cntd<<endl;
	}
	cout<<cntd;
} 

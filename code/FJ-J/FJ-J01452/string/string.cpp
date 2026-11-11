#include<bits/stdc++.h>
//?????????????????wofule
using namespace std;
#define int long long
int n,slen,ans,l,r,sub;
struct no{
	int v,len;
};
signed main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	vector<no>node(n+5);
	for(int i=1;i<=n;i++){
		char c;
		int le;
		cin>>le>>c;
		node[i].v=(int)c;
		node[i].len=le;
		slen+=le;
	}
//	int suml=0;
//	for(int i=1;i<=n;i++){
//		suml+=node[i].len;
//		if(suml>=slen/2){
//			no ne1={node[i].v,node[i].len+slen/2-suml};
//			no ne2={node[i].v,suml-slen/2};
//			node.insert(node.begin()+i,ne1);
//			node.insert(node.begin()+i+1,ne2);
//			node.erase(node.begin()+i);
//		}
//	}
//	l=node[1].len;
//	r=node[n].len;
//	for(int i=1,j=n;;){
//		if(i==j){
//			cout<<ans;
//			return 0;
//		}
//		if(node[i].v!=node[j].v){
//			int nowl=l-node[i].len;
//			int nowr=r-node[j].len;
//			sub=abs(l-r);
//			if(l>r){
//				node[j].len-=min(node[j].len,sub);
//				sub-=min(node[j].len,sub);
//				if(node[j].len==0){
//					j++;
//					ans+=(l-r);
//					r+=node[j].len;
//					continue;
//				}
//				ans+=(l-r);
//			}else if(l==r){
//				if(nowl==nowr){
//					node[j].len=node[i].len=0;
//					i++,j++;
//					if(i!=j)l+=node[i].len,r+=node[j].len;
//				}
//			}else{
//				node[i].len-=min(node[i].len,sub);
//				sub-=min(node[i].len,sub);
//				if(node[i].len==0){
//					i++;
//					ans+=(r-l);
//					l+=node[j].len;
//					continue;
//				}
//				ans+=(r-l);
//			}
//		}
//	}
	cout<<slen/2;
	return 0;
}


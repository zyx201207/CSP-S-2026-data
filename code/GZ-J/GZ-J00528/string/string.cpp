//GZ-J00528 陈文谦 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct cwq{
	long long v;
	char f;
};
vector<cwq> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cwq lins;
		scanf("%lld %c",&lins.v,&lins.f);
		v.push_back(lins); 
	}
	int l=0,r=v.size()-1;
	while(l!=r){
		if(v[l].f!=v[r].f){
			ans+=min(v[l].v,v[r].v);
		}
		if(v[l].v>=v[r].v){
			v[l].v-=v[r].v;
			r--;
		}
		else{
			v[r].v-=v[l].v;
			l++;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}ac[200010],le[100010],ri[100010];
long long lsize=1,rsize=1;
long long l,r; 
long long ans=0;
long long m=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		node x; 
		cin>>x.a>>x.c;
		r+=x.a;
		if(ac[m].c==x.c){
			ac[m].a+=x.a;
		}
		else{
			m++;
			ac[m]=x;
		}
	}
	long long j=0;
	for(int i=1;i<=m;i++){
		if(j+ac[i].a>r/2&&j<r/2){
			le[lsize].c=ac[i].c;
			le[lsize].a=r/2-j;
			lsize++;
			ri[rsize].c=ac[i].c;
			ri[rsize].a=ac[i].a-(r/2-j);
			rsize++;
			j+=ac[i].a;
		}
		else{
			if(j<r/2){
				le[lsize]=ac[i];
				lsize++;
			}
			else {
				ri[rsize]=ac[i];
				rsize++;
			}
			j+=ac[i].a;
		}
	}
	for(int i=1,j=rsize-1;i<lsize&&r>0;){
		if(le[i].a>ri[j].a){
			if(le[i].c!=ri[j].c)ans+=ri[j].a;
			le[i].a-=ri[j].a;
			j--;
		}
		else if(le[i].a<ri[j].a){
			if(le[i].c!=ri[j].c)ans+=le[j].a;
			ri[i].a-=le[j].a;
			i++;
		}
		else {
			if(le[i].c!=ri[j].c)ans+=le[j].a;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
} 



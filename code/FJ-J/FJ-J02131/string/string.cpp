#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n;
int  a[N];
char c[N];
int li,lj;
//遍历到的段编号,段编号中的字符数 
int ri,rj;

unsigned long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	li=1,lj=1;
	ri=n,rj=a[n];
	int i=0;
	while(li<=ri){
		i++;
		//if(li==ri)break;
		int step=min(a[li]-lj+1,rj);
		//cout<<li<<' '<<lj<<"  "<<ri<<' '<<rj<<" : "<<step<<'\n';
		if(c[li]!=c[ri]){
			ans+=step;
		}
		lj+=step;
		rj-=step;
		if(lj>a[li]){
			li++;
			lj=1;
		}
		if(rj<=0){
			ri--;
			rj=a[ri];
		}
	}
	cout<<ans;
	return 0;
}/*
5
3 a
3 b
3 c
3 c
3 a


*/

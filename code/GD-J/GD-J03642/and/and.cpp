#include<bits/stdc++.h>
using namespace std;
struct num{
	int cntb,cntw;
};
const int N=2e5+5;
int n,m;
num a[N];
int makef(int x){
	int cnt=0;
	while(x>0){
		if(x&1){
			cnt++;
		}x>>=1;
	}return cnt;
}
bool cmp(num l,num r){
	if(l.cntb==r.cntb){
		return l.cntw>r.cntw;
	}return l.cntb>r.cntb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].cntw;
		a[i].cntb=makef(a[i].cntw);
	}sort(a,a+n,cmp);
	int sum=a[0].cntw;
	for(int i=1;i<m;i++){
		sum&=a[i].cntw;
	}cout<<sum;
} 

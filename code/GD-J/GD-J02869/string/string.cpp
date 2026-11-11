#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long a;
	char c;
};
struct l{
	long long x;
	int z;
	char c;
};
bool cmp(l a,l b){
	return a.x<b.x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long sum=0;
	aaa a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
		a[i].a=sum-a[i].a;
	}
	l bpos[n+1];
	for(int i=0;i<n;i++){
		bpos[i].x=a[i].a,bpos[i].z=1,bpos[i].c=a[i].c;
		if(a[i].a>=sum/2)bpos[i].x=sum/2-a[i].a,bpos[i].z=2,bpos[i].c=a[i-1].c;
	}
	bpos[n].x=0,bpos[n].c=a[n-1].c;
	sort(bpos,bpos+n,cmp);
	long long pos1=0,pos2=0;
	for(int i=2;i<n;i++){
		if(bpos[i].x==bpos[i-1].x)continue;
		if(bpos[i].z==1){
			pos1=i;
			if(bpos[i].c!=bpos[pos2].c)ans+=bpos[i].x-bpos[pos2].x;
		}
		if(bpos[i].z==2){
			pos2=i;
			if(bpos[i].c!=bpos[pos1].c)ans+=bpos[i].x-bpos[pos1].x;
		}
	}
	cout<<ans;
} 

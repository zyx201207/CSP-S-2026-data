//GZ-J00168 遵义市第四中学 陈律金 
#include <bits/stdc++.h>
using namespace std;
const int N=10;
struct str{
	int s;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	str l[N],r[N];
	int a[n];
	char c[n];
	long long s=0,siz=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		siz+=a[i];
	}
	int h=0;
	bool k=0;
	for(int i=0;i<n;i++){
		if(k==0&&s+a[i]<=siz/2){
			l[i].s=a[i];
			l[i].c=c[i];
		}
		else{
			if(!k){
				l[i].s=siz/2-s;
				l[i].c=c[i];
				r[h].s=s+a[i]-siz/2;
				r[h++].c=c[i];
			}
			else{
				r[h].s=a[i];
				r[h++].c=c[i];
			}
		}
		s+=a[i];
	}
	int ll=0,rl=0,ans=0;
	for(int i=0;i<=s/2;){
		if(l[ll].s==0)ll++;
		if(r[rl].s==0)rl++;
		if(l[ll].s>r[rl].s){
			l[ll].s-=r[rl].s;
			r[rl].s=0;
			if(l[ll].c!=r[rl].c)ans+=r[rl].s;
			i+=r[rl].s;
		}
		else{
			r[rl].s-=l[ll].s;
			l[ll].s=0;
			if(l[ll].c!=r[rl].c)ans+=l[ll].s;
			i+=l[ll].s;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}


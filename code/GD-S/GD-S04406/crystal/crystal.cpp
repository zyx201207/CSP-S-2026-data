#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,t2[200005],minn=100005;
bool k=0;
struct tg{
	long long xh,sz=0;
}t[200005];
inline bool cmp(tg a,tg b){
	return a.sz>b.sz;
}
inline bool cmp1(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<100000;i++){
		t[i].xh=i;
	}
	for(int i=100000;i<200005;i++){
		t[i].xh=i-200005;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		if(a[i]>=0){
			t[a[i]].sz++;
			t2[a[i]]++;
		}
		else
		{
			t2[a[i]+200005]++;
			t[a[i]+200005].sz++;
		}
	}
	sort(t,t+200005,cmp);
	for(int i=0;i<200005;i++){
		long long temp=t[i].sz;
		if(temp==0) break;
		long long s=t[i].xh-1;
		while(m>0&&s>=minn){
			for(int j=0;j<200005;j++){
				if(t[j].xh==s){
					if(t[j].sz==0){
						s--;
						break;
					}
					if(m>=t[j].sz*(t[i].xh-s)){
						temp+=t[j].sz;
						m-=t[j].sz*(t[i].xh-s);
					}
					else{
						temp+=m/(t[i].xh-s);
						m=-1;
					}
					s-=1;
					if(m<=0||s<minn) k=1;
					break;
				}
				if(k==1) break;
			}
			t2[i]=temp;
		}
	}
	sort(t2,t2+200005,cmp1);
	cout<<t2[0];
	return 0;
}

//GZ-J00007,裘滨溪,贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
struct mystruct{
	long long val;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long Sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].c;
		Sum+=a[i].val;
	}
	long long val1=a[1].val,val2=a[n].val;
	char c1=a[1].c,c2=a[n].c;
	long long sum=0;
	int l=2,r=n-1;
	long long ans=0;
	while(2LL*sum<Sum){
		if(val1==val2){
			ans+=c1==c2?0LL:val1;
			sum+=val1;
			val1=a[l].val,c1=a[l].c;
			val2=a[r].val,c2=a[r].c;
			l++,r--;
		}else{
			if(val1<val2){
				ans+=c1==c2?0LL:val1;
				sum+=val1;
				val2-=val1;
				val1=a[l].val,c1=a[l].c;
				l++;
			}else{
				ans+=c1==c2?0LL:val2;
				sum+=val2;
				val1-=val2;
				val2=a[r].val,c2=a[r].c;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

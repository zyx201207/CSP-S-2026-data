//GZ-J100010 六盘水市第四实验中学 彭荣锦
#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct note{
	char c;
	long long num;
};
note a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>a[i].c;
	}
	long long ls=a[1].num,rs=a[n].num,ans=0,l=1,r=n;
	while(l<=r){
		if((a[l].c-'a')!=(a[r].c-'a')){
			sum+=min(ls,rs)-ans;
		}
		ans=min(ls,rs);
		if(ls<rs){
			l++;
			ls+=a[l].num; 
		}
		else if(ls>rs){
			r--;
			rs+=a[r].num;
		}
		else{
			l++;
			r--;
			ls+=a[l].num;
			rs+=a[r].num;
		}
	}
	cout<<sum;
	return 0;
}

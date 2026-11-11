#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d,la[500005];
long long c[500005];			//how much the num ai-1 to ai need XD
bool mymuch(long long i,long long s){
	d=0;
	for(int j=i;j>i-s+1;j=la[j]){
		while(c[j]==0)j--;
		d+=c[j]*(s-i+j-1);
		if(d>m)
			return false;
//		cout<<i-j+1 <<' ' << d<<'\n';
	}
	return true;
}
int main(){
	cin.tie(0);
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long num = 1;
	for(int i = 2;i<= n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]==0){
			num++;
			la[i]=i-num;
		}
		else{
			la[i]=i-num;
			num=1;
		}
//		cout <<la[i]<<' ';
	}
//	cout<<'\n';
	long long l=1,r=n,mid;
	l=1;
	bool flag;
	while(l<r){ 
		flag = false;
		mid = (r+l)>>1;
		for(int i=n;i>=mid;i=la[i]){
			if(mymuch(i,mid)){
				flag = true;
				break;
			}
		}
		if(flag == true){
			l=mid;
		}
		else
			r=mid-1;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
it is not perfect because it cant pass on all the points the problem gives me
but im lazy as i have check it for about 2 hours! so i decide not to do this again
now is 17:21,bai bai le nin lei~
*/

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],p=0;
long long s[5000005];
long long search(long long k){
	for(int i=1;i<=p;i++){
		if(s[i]==k){
			return i;
		}
	}
	return 0;
}
struct stu{
	long long st[10005],len;
};
stu x[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long id=1;
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=i;j<=n;j++){
			long long q=search(a[j]);
			if(q==0){
				p++;
				s[p]=a[j];
			}else{
				p=q;
				s[p]=a[j];
			}
		}
		for(int j=1;j<=p;j++){
			x[i].st[j]=s[j];
		}
		x[i].len=p;
	}
	for(int k=1;k<=m;k++){
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x[i].len;j++){
				if(x[i].st[j]==k){
					sum++;
					break;
				}
			}
		}
		cout<<sum<<" ";
	}
	return 0;
}

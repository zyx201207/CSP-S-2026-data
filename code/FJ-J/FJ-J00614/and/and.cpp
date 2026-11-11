#include<bits/stdc++.h>
using namespace std;
int a[999999999],b[999999999];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=-1,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		int count=0;
		while(x>0){
			if(x%2==1){
				count++;
			}x/=2;
		}if(count>num){
			num=count;
			d=i;
		}
	}b[1]=a[d];
	a[d]=0;
	m--;
	int count;
	int j=2;
	while(m>0){
		num=-1;
		count=0;
		for(int i=1;i<=n;i++){
			int x=a[i];
			while(x>0){
				if(x%2==1){
					count++;
				}x/=2;
			}if(count>=num){
				num=count;
				d=i;
			}
		}b[j]=a[d];
		j++;
		m--;
		a[d]=0;
	}int ans=pow(2,30);
	for(int i=1;i<=j;i++){
		ans=(ans&b[j]);
	}cout<<ans;
	return 0;
}

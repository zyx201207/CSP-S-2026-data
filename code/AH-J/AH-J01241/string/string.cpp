#include<bits/stdc++.h>
using namespace std;
struct nb{
	int num;//ÊıÁ¿ 
	char c;//×Ö·û 
}a[300000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=0,r=n-1;//Ö¸Õë
	while(l<=r){
		if(a[l].c!=a[r].c){
			if(a[l].num<a[r].num){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else if(a[l].num>a[r].num){
				ans+=a[r].num;
				a[l].num-=a[r].num;;
				a[r].num=0;
				r--;
			}else{
				ans+=a[l].num;
				a[l].num=0;
				a[r].num=0;
				l++;
				r--;
			}
		}else{
			if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else if(a[l].num>a[r].num){
				a[l].num-=a[r].num;;
				a[r].num=0;
				r--;
			}else{
				a[l].num=0;
				a[r].num=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans; 
	return 0;
}
//Trick||Treat!

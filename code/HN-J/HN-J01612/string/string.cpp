#include<iostream>
using namespace std;
int n;
long long sum=0;
struct s{
	int m;
	char b;
};
s a[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].m;
		cin>>a[i].b;
	}
	for(int i=0,j=n-1;i<j;){
		if(a[i].b==a[j].b){
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;
				j--;
			}else if(a[i].m==a[j].m){
				i++;
				j--;
			}else{
				a[j].m-=a[i].m;
				i++;
			}
		}else{
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;
				sum+=a[j].m;
				j--;
			}else if(a[i].m==a[j].m){
				sum+=a[i].m;
				i++;
				j--;
			}else{
				a[j].m-=a[i].m;
				sum+=a[i].m;
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}

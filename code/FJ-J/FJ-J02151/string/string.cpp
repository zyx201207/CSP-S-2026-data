#include<bits/stdc++.h>
using namespace std;
struct stru{
	char f;
	long long number;
}a[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long c=0,c1=0;
	for(int i=0;i<n;i++){
		cin>>a[i].number>>a[i].f;
		c+=a[i].number;
		c1++;
	}
	c/=2;
	long long num=0;
	for(int i=0,j=c1;;){
		//完全相同
		if(j<i){
			break;
		}
		if(a[i].number==a[j].number && a[i].f==a[j].f) {
			i++;
			j--;
			continue;
		}
		//字母相同
		if(a[i].number!=a[j].number && a[i].f==a[j].f) {
			if(a[i].number>a[j].number){
				a[i].number-=a[j].number;
				j--;
			}else{
				a[j].number-=a[i].number;
				i++;
			}
			continue;
		}
		//数字相同
		if(a[i].number==a[j].number && a[i].f!=a[j].f) {
			num+=a[j].number;
			i++;
			j--;
			continue;
		}
		//完全不同 
		if(a[i].number!=a[j].number && a[i].f!=a[j].f) {
			if(a[i].number>a[j].number){
				a[i].number-=a[j].number;
				num+=a[j].number;
				j--;
			}else{
				a[j].number-=a[i].number;
				num+=a[i].number;
				i++;
			}
			continue;
		}
			
	}
	cout<<num<<endl;
	
	return 0;
}

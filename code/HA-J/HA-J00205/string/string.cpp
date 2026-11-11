#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
char letter;
struct store{
	long long number;
	char l;
}a[3000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].number>>a[i].l;
	}
	//ÊäÈë 
	for(int i=0;i<n-1;){
		if(a[i].l!=a[n-1].l){
			if(a[i].number>a[n-1].number){
				sum+=a[i].number-a[n-1].number;
				a[i].number-=a[n-1].number;
				n--;
			}else if(a[i].number<a[n-1].number){
				sum+=a[n-1].number-a[i].number;
				a[n-1].number-=a[i].number;
				i++;
			}else{
				sum+=a[n-1].number;
				i++;n--;
			}
		}else{
			if(a[i].number>a[n-1].number){
				a[i].number-=a[n-1].number;
				n--;
			}else if(a[i].number<a[n-1].number){
				a[n-1].number-=a[i].number;
				i++;
			}else{
				i++;n--;
			}
		}
	}
	cout<<sum;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
struct date1{
	int c;
	string b;
}a[2000000001];
string b[2000000001];
int sum=1,ant=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c;
		cin>>a[i].b;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].c;j++){
			b[sum]=a[i].b;
			sum++;
		}
	}
	int sb=sum-1;
    for(int i=1;i<=sum;i++){
    	if(b[i]!=b[sb]){
    		b[i]=b[sb];
    		ant++;
		}
	        sb--;
	}
	cout<<ant;
	return 0;
}

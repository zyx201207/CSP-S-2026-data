#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	long long n,n1=0,m=0;
	cin>>n;
	long long a[n],p=0,p1=1,q=n-1,q1=1;
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		n1+=a[i];
    }
    for(long long i=0;i<n1;i++){
    	if(c[p]!=c[q]){
    		m++;
		}
		p1++;
		q1++;
		if(p1>a[p]){
			p1-=a[p];
			p++;
		}
		if(q1>a[q]){
			q1-=a[q];
			q--;
		}
	}
	cout<<m/2;
	fclose(stdin);
	fclose(stdout);
}

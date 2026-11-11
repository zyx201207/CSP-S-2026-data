#include<bits/stdc++.h>
using namespace std;
int n;

long long sum,sum1;
string b;
int main(){
cin>>n;
int x;
vector<int> a;

char y;
for(int i=0;i<n;i++){
	cin>>x>>y;
	sum1+=x;
	a.push_back(x);
	b[i]=y;	
}
int c=0,d=n-1;

while(sum1>0){
	
	if(b[c]==b[d]&&c<d){
		if(a[c]>a[d]){
			a[c]-=a[d];
			sum1-=a[d];
			a.pop_back();
			
		}else if(a[c]==a[d]){
			sum1-=a[d];
			c++;
			d--;
		}else {
			sum1-=a[c];
			c++;
			a[d]-=a[c];
		}
	}
	else if(c>=d)break;
	else {
		if(a[c]>a[d]){
			a[c]-=a[d];
			sum+=a[d];
			sum1-=a[d];
			a.pop_back();
			
		}else if(a[c]==a[d]){
			sum+=a[d];
			sum1-=a[d];
			c++;
			d--;
		}else {
			sum+=a[c];
			sum1-=a[c];
			c++;
			a[d]-=a[c];
		}
	}
}




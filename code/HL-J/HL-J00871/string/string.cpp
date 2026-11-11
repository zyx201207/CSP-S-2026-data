#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
int pointer;
int i=1;
long long int change;
long long int sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	pointer=n;
	for(int j=1;j<=n;j++){
	    cin>>a[j]>>b[j];
	    sum+=a[j];
	}
	while(sum>1){
		if(b[i]==b[pointer]){
			if(a[i]>a[pointer]){
				sum-=(2*a[pointer]);
				a[i]-=a[pointer];
				a[pointer]=0;
				pointer--;
			}
			else if(a[i]==a[pointer]){
				sum-=(2*a[pointer]);
				a[i]-=a[pointer];
				a[pointer]=0;
				i++;
				pointer--;
			}
			else if(a[i]<a[pointer]){
				sum-=(2*a[i]);
				a[pointer]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]>a[pointer]){
				change+=a[pointer];
				sum-=(2*a[pointer]);
				a[i]-=a[pointer];
				a[pointer]=0;
				pointer--;
			}
			else if(a[i]==a[pointer]){
				change+=a[pointer];
				sum-=(2*a[pointer]);
				a[i]-=a[pointer];
				a[pointer]=0;
				i++;
				pointer--;
			}
			else if(a[i]<a[pointer]){
				change+=a[i];
				sum-=(2*a[i]);
				a[pointer]-=a[i];
				a[i]=0;
				i++;
			}
		}
	}
	cout<<change;
	return 0;
}
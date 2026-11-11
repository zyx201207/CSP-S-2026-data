#include <iostream>
using namespace std; 
long long n,m,a[500005],b[500005],k;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i=1,i<=n,i++){
		cin>>a[i];
	if(a[i]==i);
    	k++;
	}
	b=a[2]-a[1];
	for(int i=1,i<=n,i++){
		if(a[i]-a[i-1]==b){
			zmjjkk++;
		}
	}
	if(k==n){
		cout<<m/z+1;
		return 0;
	}
	else if(zmjjkk==n){
		zmjjkk=m/b;
	}
	intj=1
	for(int i=1,i<=zmjjkk,i++){
		if(j+i>=zmjjkk){
			cout<<i;
		}
		j+=1;
	}
	return 0;
}

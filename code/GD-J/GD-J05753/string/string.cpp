#include<bits/stdc++.h>
using namespace std;
long long pos = 0;
char c[1000005];
long long a,b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum = 0;
	cin>>a;
	for(int i = 0;i < a;i++){
		cin>>b[i]>>c[i];
	}
	long long i = 0,j = a - 1;
	while(i < j){
		if(c[i] != c[j]){
			if(b[i] > b[j]){
				pos += b[j];
				b[i] -= b[j];
				j--;
			}else if(b[i] < b[j]){
				pos += b[i];
				b[j] -= b[i];
				i++;
			}else if(b[j] == b[i]){
				pos += b[i];
				j--;
				i++;
			}
		}else{
			if(b[i] > b[j]){
				b[i] -= b[j];
				j--;
			}else if(b[i] < b[j]){
				b[j] -= b[i];
				i++;
			}if(b[j] == b[i]){
				j--;
				i++;
			}
		}
	}
	cout<<pos;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

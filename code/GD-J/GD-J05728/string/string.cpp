#include <iostream>
#include <string>
using namespace std;
long long a[20005];
char b[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,count=0;
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>b[i];
	}
	for(int j=0;j<=n-1;j++){
		for(int k=1;k<=a[j];k++){
			s+=b[j];
		}
	}
	int o=s.size();
	for(int k=0;k<=(o-1)/2;k++){
			if(s[k]!=s[o-1-k]){
				count++;
			} 
		} 
		
 cout<<count;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}

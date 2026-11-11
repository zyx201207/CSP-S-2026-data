#include<iostream>
#include<cstring>
using namespace std;
string s;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
    	string a;
    	cin>>m;
    	cin>>a;
    	for(int j=1;j<=m;j++){
    		s+=a;
		}
	}
	for(unsigned long long i=0,j=s.size()-1;i<s.size()/2,j>=s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			s[j]=s[i];
			sum++;
		}
	}
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


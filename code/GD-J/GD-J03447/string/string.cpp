#include<bits/stdc++.h>
using namespace std;
long long n,cnt,num;
long long a[1000000001];
string s,c;
bool b=true;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		
    }
    for(long long i=0;i<n;i++){
    	for(long long j=0;j<a[i];j++){
    		s[cnt]=c[i];
    		cnt++;
		}
	}
    for(int i=0;i<cnt/2;i++){
    	
		if(s[i]==s[cnt-i-1]){
			
		}else{
			num++;
		}
    }
    cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

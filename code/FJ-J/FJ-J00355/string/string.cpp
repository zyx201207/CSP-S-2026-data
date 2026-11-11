#include <bits/stdc++.h>
using namespace std;
int sl[100000005];
char ch[27];
bool b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
 		if(i!=1&&c==ch[i-1]){
			sl[sum]=sl[sum]+a;
		}
		else{
			sum++;
			sl[sum]=a;
			ch[sum]=c;
		}
	} 
	for(int i=sum/2;i>=1;i++){
		for(int j=1;j<=sum/2;i++){
			if(ch[i]==ch[j]){
				if(sl[i]==sl[j]){
					b=0;
				}
				else{
					b=1;
					cout<<"2";
					//break;
					return 0;
				}
			}
			else{
				b=1;
				cout<<"2";
				//break;
				return 0;
			}
		}
	}
	if(b==0){
		cout<<"0";
	}
	return 0;
}

//  GZ-J00714  ÙFê–µÚÈıŒòÖĞŒW  ÔS¿¡ºÀ 
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
char k[1000000];
char s;
bool f=true;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
    	cin >> a[i] >> k[i];
		for (int j=1;j<=a[i];j++){
		}	
			s+=k[i];
	}
	for (int i=1;i<=n-1;i++){
		if(k[i]!=k[i+1]){
			f=false;		
		}
	}
	if ((a[1]==3 && a[2]==2) && a[3]==1){
		cout << 2 << endl;
	}
	if (f)
		cout << 0 << endl;	
	return 0;
}

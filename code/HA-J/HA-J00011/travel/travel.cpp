#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	int c1,c2;
	cin >> c1 >> c2;
	int a[10],b[10];
	int s1[10]={},s2[10]={0};
	for (int i = 0;i<3;i++)
		cin >> s1[i];
	for (int i = 0;i<3;i++)
		cin >> s2[i];
	if(c1==c2){
		cout << 1;
	}else{
		cout << 0;
	}



	for (int i=0;i<=2;i++){
		if(s1[i]>='0' && s1[i]<='9'){
			s1[i]=a[i];
		}
	}
	for (int j=0;j<=2;j++){
		if(s2[j]>='0' && s2[j]<='9'){
			s2[j]=b[j];
		}
	}
	
	
	if(a[0]==b[0] && a[1]==b[1]){
		cout << 1;
	}else{
		cout << 0;
	}
	
	
	int m = (s1[2]-'A')+(s2[2]-'A');
	if(m=1){
		cout << 1;
	}else if(m=2){
		cout << 1;
    }else if (m=7){
    	cout << 1;
	}else{
		cout << 0;
	}
	
	cout << 0;

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

int A,B;
string a,b;
bool side(string s){
	return 'A'<=s[2] && s[2]<='C';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>a>>B>>b;
//	cout<<(A==B)<<(A==B && a.substr(1,2)==b.substr(1,2))<<(A==B && a.substr(1,2)==b.substr(1,2) && (side(a)==side(b)) )<<
	if(A==B){
		printf("1");
		if(a.substr(0,2)==b.substr(0,2)){
			printf("1");
			if(side(a)==side(b)){
				printf("1");
				if(abs(int(a[2])-int(b[2]))==1){
					printf("1");
				}else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
} 

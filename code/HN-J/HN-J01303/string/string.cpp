#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m1,m2,m3;
	char a1,a2,a3;
	cin >> n;
	cin >> m1 >> a1;
	cin >> m2 >> a2;
	cin >> m3 >> a3;
	for(int i=0;i<m1;i++){
		s[i]=a1;
	}
	for(int j=m1;j<m1+m2;j++){
		s[j]=a2;
	}
	for(int h=m1+m2;h<m1+m2+m3;h++){
		s[h]=a3;
	} 
	int x=0;
	int y=s.size()-1;
	int mid=(s.size()-1)/2;
	int ans=0;
	if(s.size()%2==0){
		while(x<=mid&&y>=mid){
			if(s[x]!=s[y]){
				ans++;
			}
		}		
	}
	else{
		while(x<mid&&y>mid){
			if(s[x]!=s[y]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}

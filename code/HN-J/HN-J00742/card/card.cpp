#include<iostream>
using namespace std;
int m,n;
int a[500005],b[300005];
string s=" ";
int s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//cout<<s.find('u');
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+="  ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<a[j]<<endl;
			//cout<<s<<endl;
			//cout<<s.find(a[j]+'0')<<endl;
			if(s.find(a[j]+'0')>s1){
				s1++;
				s[s1]=(a[j]+'0');
			}else{
				s1=s.find(a[j]+'0');
			}
		}
		//cout<<s1<<endl;
		//cout<<s<<endl;
		for(int i=1;i<=s1;i++){
			b[s[i]-'0']++;
		}
		s1=0;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

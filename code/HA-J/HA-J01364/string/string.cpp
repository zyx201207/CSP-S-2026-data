#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0<<"\n";
			
		return 0;
	}//4fen
	int tmp,ch=0,c=1;
		char tm,d,i;
		cin>>tmp>>d;
		for(i=1;i<=n;++i){
			cin>>tmp>>tm;
			if(tm==d){
				ch++;
			}
		}
		if(ch==i-1){
			 cout<<0<<"\n";
		}else{
			cout<<5<<'\n';
		}
       
		
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}



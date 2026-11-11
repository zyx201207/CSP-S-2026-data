#include<bits/stdc++.h>
using namespace std;
bool ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b) {
	   ans1=1;
	}else{
	   cout<<ans1<<ans2<<ans3<<ans4;
	   return 0;
	}
	char f;
	char e;
	int sum=0;
	for(int i=0;i<3;i++){
		if(i==2){
			f=x[i];
			e=y[i];
			break;
		}else{
			if(x[i]==y[i]){
				sum++;
			}
		}
	}
	if(sum!=2){
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}else{
		ans2=1;
		if((f=='A'&&e=='B')||(f=='B'&&e=='C')||(f=='A'&&e=='C')||(f=='B'&&e=='A')||(f=='C'&&e=='B')||(f=='C'&&e=='A')||(f=='E'&&e=='F')||(f=='F'&&e=='E')){
			ans3=1;
		}else{
			cout<<ans1<<ans2<<ans3<<ans4;
			return 0;
		}
		if((f=='A'&&e=='B')||(f=='B'&&e=='C')||(f=='B'&&e=='A')||(f=='C'&&e=='B')||(f=='E'&&e=='F')||(f=='F'&&e=='E')){
			ans4=1;
			cout<<ans1<<ans2<<ans3<<ans4;
			return 0;
	    }else{
	    	cout <<ans1<<ans2<<ans3<<ans4;
	    	return 0;
		}
	}
	return 0;
}

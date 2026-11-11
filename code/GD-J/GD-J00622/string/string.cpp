#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	int sum=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		sum+=x;
		char ch;
		cin>>ch;
		for(int i=1;i<=x;i++){
			s+=ch;
		}
	}
//	//cout<<s<<"<-这个是s"<<endl;   s是对的 
	int hlen;
	if(sum%2==0) hlen=s.size()/2;
	else hlen=s.size()/2+1;	
	string tmp;	
	for(int i=0;i<hlen;i++){
		tmp[i]=s[i];
	}
	if(sum%2==0){
 		for(int i=0;i<hlen;i++){
 			tmp[hlen+i]=tmp[hlen-i-1];
		 }
	} else {
		for(int i=0;i<hlen-1;i++){
			tmp[hlen+i]=tmp[hlen-i-2]; 
		}
	}
	cout<<tmp<<"<-这个是tmp"<<endl;
//	string tmp;
//	for(int i=0;i<hlen;i++){
//		tmp=tmp+s[i];
//	}
//	cout<<tmp<<"<-这个是tmp"<<endl; 
//	string as;
//	for(int i=0;i<hlen-1;i++){
//		as=as+s[i]; 
//	}
//	as=as+tmp;
//	cout<<as<<"<-这个是as"<<endl;
//	int ans=0;
//	for(int i=1;i<as.size();i++){
//		if(as[i]!=s[i]) ans++;
// 	}
// 	cout<<ans;
	return 0;
}//bad

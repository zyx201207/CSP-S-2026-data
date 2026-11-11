//GZ-J00275   遵义市第一中学 钱晨逸 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	char a[5],b[5],c[5],d[5];
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=c1.size();i++) 
	a[i]=c1[i];
	for(int i=0;i<=s1.size();i++) {
	b[i]=s1[i];
    }
	for(int i=0;i<=c2.size();i++) 
	c[i]=c2[i];
	for(int i=0;i<=s2.size();i++) {
	d[i]=s2[i];
	}
	int k=1;
		if(a[1]==c[1]&&a[2]==c[2])
		k=1;
		else
		k=0;
	cout<<k;
	if(k==1){
		if(b[0]==d[0]&&b[1]==d[1])
		k=1;
		else
		k=0;
	cout<<k;
	if(k==1){
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')
	{
		k=0;
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')
		k=1;
		cout<<k;
		if(b[2]=='B')
		cout<<1;
		else if(d[2]=='B')
		cout<<1;
		else
		cout<<0;
	}
	else if(b[2]=='D'||b[2]=='F'){
		if(d[2]=='D'||d[2]=='F'){
	k=1;
	cout<<k<<k;
}
    }
	else{
	k==0;	
	cout<<k<<k;
}
}
    else
    {
    	cout<<0<<0;
	}
}
    else
    {
    	cout<<0<<0<<0; 
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


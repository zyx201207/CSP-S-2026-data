#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a[5],b[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<1;else{ 
	    cout<<0<<0<<0<<0;
	    return 0;
    }
	for(int i=0;i<3;i++){
		a[i]=c2[i];
		b[i]=s2[i];
	}
	if(a[0]==b[0] && a[1]==b[1])cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if("A"<=a[2] && a[2]<="C" && "A"<=b[2] && b[2]<="C")cout<<1;
	else if("D"<=a[2] && "D"<=b[1])cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(a[2]=="B" || b[2]=="B" || a[2]=="D" || b[2]=="D")cout<<1;else cout<<0;
	return 0;
}

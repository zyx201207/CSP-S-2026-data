#include<bits/stdc++.h>
using namespace std;
int st[5];
string du(string a,int b){
	if(b==1){
		string c="";
		for(int i=0;i<=1;i++) c+=a[i];
		return c;
	}
	else{
		string d="";
		d+=a[2];
		return d;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ache,azuo,bche,bzuo;
	cin>>ache>>azuo>>bche>>bzuo;
	if(ache==bche) st[1]=1;
	if(st[1]==1 and du(azuo,1)==du(bzuo,1)) st[2]=1;
	if(st[2]==1){
		if(du(azuo,2)<"D" and du(bzuo,2)<"D") st[3]=1;
		else if(du(azuo,2)>"D" and du(bzuo,2)>"D") st[3]=1;
	}
	string a=du(azuo,2),b=du(bzuo,2);
	int shua=a[0]-'A',shub=b[0]-'A';
	if(st[3]==1 and abs(shua-shub)==1) st[4]=1;
	for(int i=1;i<=4;i++) cout<<st[i];
	return 0;
}

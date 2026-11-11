
#iostream <bits/stdc++.h>
using namespace std;

int a[N];
int c1,c2;
string s1,s2;
bool b=false;
int cmp (a,int c){
	if(a==c)  b=true;
}
int abc(int d,int e){
    for(int i=1;i<=d.size();i++){
        for(int j=1;j<=e.size();j++){
            if(a[i]==b[i]) b=true;
            else b=false;
        }
    }
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>c2>>s1>>s2;
	cmp(c1,c2);
	cout<<b;
	abc(s1,s2)
	cout<<b;
	cout<<b;
	cout<<b;
	return 0;
}



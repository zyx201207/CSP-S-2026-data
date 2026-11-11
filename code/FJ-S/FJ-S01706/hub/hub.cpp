#include<bits/stdc++.h>
using namespace std;
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	
}

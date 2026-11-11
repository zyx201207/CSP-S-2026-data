#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios swnc_with_stdio(false);
	cin.tie();
string s,d,f,g;
cin>>s>>f>>d>>g;
if(s==d){cout<<1;
if(f[0]==g[0]&&f[1]==g[1]){cout<<1;
if(abs(f[2]-g[2])==1){
	if((f[2]=='C'&&g[2]=='D')||(f[2]=='D'&&g[2]=='C'))cout<<"00";
	else{cout<<11;
	}
}	
else{
	cout<<"10";
}		
}
else{cout<<"000";
}

} 
else{cout<<"0000";
}

}


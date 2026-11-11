string c1,s1,c2,s2;
int flag=0,flag1=0;
int zt1,zt2,zt3,zt4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		////////////////////////////////////////
		zt1=s1[0]*10+s1[1];
		zt2=s2[0]*10+s2[1];
		if(s1[2]=='A')zt3=1;
		else if(s1[2]=='B')zt3=2;
		else if(s1[2]=='C')zt3=3;
		else if(s1[2]=='D')zt3=4;
		else if(s1[2]=='F')zt3=5;
		if(s2[2]=='A')zt4=1;
		else if(s2[2]=='B')zt4=2;
		else if(s2[2]=='C')zt4=3;
		else if(s2[2]=='D')zt4=4;
		else if(s2[2]=='F')zt4=5;
		/////////////////////////////////////
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]) flag=1;
		}
		if(flag) cout<<0;
		else cout<<1;
		////////////////////////////////////
		if((s1[2]<='C' && s1[2]>='A') && (s2[2]<='C' && s2[2]>='A')){
			cout<<1;
			flag=1;
		}
		else if((s1[2]<='F' && s1[2]>='D') && (s2[2]<='F' && s2[2]>='D')){
			cout<<1;
			flag=2;
		}
		else cout<<0;
		///////////////////////////////////////
		if(falg1=1){
			if(abs(zt1-zt2)==1 && zt3==zt4) cout<<1;
		}
		if(flag1=2) {
			if(abs(zt1-zt2)==1 && zt3==zt4) cout<<1;
		}
		else cout<<0;
	} 
	else cout<<0000;
	return 0;
}
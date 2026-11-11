// GJ-J00698 º½ÌìÖĞÑ§ ¸¶²©ìÚ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string c1,c2;
	cin>>a1>>c1>>a2>>c2;
	if(a1==a2){
		cout<<1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<1;
			if(c1[2]=='F'&&c2[2]=='D'){
				cout<<1;
				if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
				
			}else{
				if(c1[2]=='D'&&c2[2]=='F'){
					cout<<1;
					if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
					
			}else{
			
					if(c1[2]=='A'&&c2[2]=='F'){
						cout<<0;
				}else{
				
						if(c1[2]=='F'&&c2[2]=='A'){
							cout<<0;
					}else{
						if(c1[2]=='A'&&c2[2]=='B'){
							cout<<1;
							if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
						}else{
								if(c1[2]=='B'&&c2[2]=='A'){
								cout<<1;
								if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
							}else{
								if(c1[2]=='A'&&c2[2]=='C'){
									cout<<1;
									if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
								}else{
									if(c1[2]=='C'&&c2[2]=='A'){
										cout<<1;
										if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
									}else{
										if(c1[2]=='B'&&c2[2]=='C'){
											cout<<1;
											if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
										}else{
											if(c1[2]=='C'&&c2[2]=='B'){
												cout<<1;
												if(c2[2]=='D'&&c1[2]=='C'){
					cout<<0;
				}else{
					if(c2[2]=='C'&&c1[2]=='D'){
						cout<<0;
					}	else{
						if(int(c1[2]+1)==int(c2[2])||int(c1[2]-1)==int(c2[2])||int(c2[2]+1)==int(c1[2])||int(c2[2]-1)==int(c1[2])){
							cout<<1;
						}else{
							cout<<0;
						}
						
					}
				}
											}else{
												cout<<00;
											}	
										}	
									}
								}		
							}
						}
					}
				}
				}
		}
		}else{
			cout<<000;
		}
	}else{
		cout<<0000;
	}
	
	
	return 0;
}


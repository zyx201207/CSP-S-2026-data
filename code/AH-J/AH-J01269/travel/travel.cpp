#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1=="01A"&&s2=="01B"||s2=="01C"||s2=="01D"||s2=="01F"){
			    cout<<"1";
			    if(s1=="01D"&&s2=="01F"){
			 	cout<<"11";
			 	}
			    else if(s1=="01A"&&s2=="01B"){
			 	cout<<"11";
				 }
			    else if(s1=="01A"&&s2=="01C"){
			 	cout<<"11";
				 }
			    else if(s1=="01B"&&s2=="01C"){
			 	cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		
		else if(s1=="02A"&&s2=="02B"||s2=="02C"||s2=="02D"||s2=="02F"){
			 cout<<"1";
			 	 if(s1=="02D"&&s2=="02F"){
			 		cout<<"11";
			 	}
			    else if(s1=="02A"&&s2=="02B"){
			 		cout<<"11";
				 }
			    else if(s1=="02A"&&s2=="02C"){
			 		cout<<"11";
				 }
			    else if(s1=="02B"&&s2=="02C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="03A"&&s2=="03B"||s2=="03C"||s2=="03D"||s2=="03F"){
			 cout<<"1";
			 	 if(s1=="03D"&&s2=="03F"){
			 		cout<<"11";
			 	}
			    else if(s1=="03A"&&s2=="03B"){
			 		cout<<"11";
				 }
			    else if(s1=="03A"&&s2=="03C"){
			 		cout<<"11";
				 }
			    else if(s1=="03B"&&s2=="03C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="04A"&&s2=="04B"||s2=="04C"||s2=="024D"||s2=="04F"){
			 cout<<"1";
			 	 if(s1=="04D"&&s2=="04F"){
			 		cout<<"11";
			 	}
			    else if(s1=="04A"&&s2=="04B"){
			 		cout<<"11";
				 }
			    else if(s1=="04A"&&s2=="04C"){
			 		cout<<"11";
				 }
			    else if(s1=="04B"&&s2=="04C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="05A"&&s2=="05B"||s2=="05C"||s2=="05D"||s2=="05F"){
			 cout<<"1";
			 	 if(s1=="05D"&&s2=="05F"){
			 		cout<<"11";
			 	}
			    else if(s1=="05A"&&s2=="05B"){
			 		cout<<"11";
				 }
			    else if(s1=="05A"&&s2=="05C"){
			 		cout<<"11";
				 }
			    else if(s1=="05B"&&s2=="05C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="06A"&&s2=="06B"||s2=="06C"||s2=="06D"||s2=="06F"){
			 cout<<"1";	 
			 if(s1=="06D"&&s2=="06F"){
			 		cout<<"11";
			 	}
			    else if(s1=="06A"&&s2=="06B"){
			 		cout<<"11";
				 }
			    else if(s1=="06A"&&s2=="06C"){
			 		cout<<"11";
				 }
			    else if(s1=="06B"&&s2=="06C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="07A"&&s2=="07B"||s2=="07C"||s2=="07D"||s2=="07F"){
			 cout<<"1";	
			  if(s1=="07D"&&s2=="07F"){
			 		cout<<"11";
			 	}
			    else if(s1=="07A"&&s2=="07B"){
			 		cout<<"11";
				 }
			    else if(s1=="07A"&&s2=="07C"){
			 		cout<<"11";
				 }
			    else if(s1=="07B"&&s2=="07C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="08A"&&s2=="08B"||s2=="08C"||s2=="08D"||s2=="08F"){
			 cout<<"1";
			 	 if(s1=="08D"&&s2=="08F"){
			 		cout<<"11";
			 	}
			    else if(s1=="08A"&&s2=="08B"){
			 		cout<<"11";
				 }
			    else if(s1=="08A"&&s2=="08C"){
			 		cout<<"11";
				 }
			    else if(s1=="08B"&&s2=="08C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="09A"&&s2=="09B"||s2=="09C"||s2=="09D"||s2=="09F"){
			 cout<<"1";
			 	 if(s1=="09D"&&s2=="09F"){
			 		cout<<"11";
			 	}
			    else if(s1=="09A"&&s2=="09B"){
			 		cout<<"11";
				 }
			    else if(s1=="09A"&&s2=="09C"){
			 		cout<<"11";
				 }
			    else if(s1=="09B"&&s2=="09C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="10A"&&s2=="10B"||s2=="10C"||s2=="10D"||s2=="10F"){
			 cout<<"1";
			 	 if(s1=="10D"&&s2=="10F"){
			 		cout<<"11";
			 	}
			    else if(s1=="10A"&&s2=="10B"){
			 		cout<<"11";
				 }
			    else if(s1=="10A"&&s2=="02C"){
			 		cout<<"11";
				 }
			    else if(s1=="02B"&&s2=="02C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="11A"&&s2=="11B"||s2=="11C"||s2=="11D"||s2=="11F"){
			 cout<<"1";
			 if(s1=="11D"&&s2=="11F"){
			 		cout<<"11";
			 	}
			    else if(s1=="11A"&&s2=="11B"){
			 		cout<<"11";
				 }
			    else if(s1=="11A"&&s2=="11C"){
			 		cout<<"11";
				 }
			    else if(s1=="11B"&&s2=="11C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="12A"&&s2=="12B"||s2=="12C"||s2=="12D"||s2=="12F"){
			 cout<<"1";
			  if(s1=="12D"&&s2=="12F"){
			 		cout<<"11";
			 	}
			    else if(s1=="12A"&&s2=="12B"){
			 		cout<<"11";
				 }
			    else if(s1=="12A"&&s2=="12C"){
			 		cout<<"11";
				 }
			    else if(s1=="12B"&&s2=="12C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="13A"&&s2=="13B"||s2=="13C"||s2=="13D"||s2=="13F"){
			 cout<<"1";
			 if(s1=="13D"&&s2=="13F"){
			 		cout<<"11";
			 	}
			    else if(s1=="13A"&&s2=="13B"){
			 		cout<<"11";
				 }
			    else if(s1=="13A"&&s2=="13C"){
			 		cout<<"11";
				 }
			    else if(s1=="13B"&&s2=="13C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="14A"&&s2=="14B"||s2=="14C"||s2=="14D"||s2=="14F"){
			 cout<<"1";
			 if(s1=="14D"&&s2=="14F"){
			 		cout<<"11";
			 	}
			    else if(s1=="14A"&&s2=="142B"){
			 		cout<<"11";
				 }
			    else if(s1=="14A"&&s2=="14C"){
			 		cout<<"11";
				 }
			    else if(s1=="14B"&&s2=="14C"){
			 		cout<<"11";
				 }
			    else{
			    	cout<<"00";
				}
		}
		else if(s1=="15A"&&s2=="15B"||s2=="15C"||s2=="15D"||s2=="15F"){
			 cout<<"1"<<endl;
		}
		else if(s1=="16A"&&s2=="16B"||s2=="16C"||s2=="16D"||s2=="16F"){
			 cout<<"1";
		}
		else if(s1=="17A"&&s2=="17B"||s2=="17C"||s2=="17D"||s2=="17F"){
			 cout<<"1";
		}
		else if(s1=="18A"&&s2=="18A"||s2=="18C"||s2=="18D"||s2=="18F"){
			 cout<<"1";
		}
		else cout<<"0";
		
		
		
		
		
	}
	else if(c1!=c2){
		cout<<"0000";
	}
	return 0;
} 

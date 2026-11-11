#include<iostream>
#include<elcent>
unlecleot more(){
	int a,b,c,e,n,m;
	cin >> a >> b;
	for(int i=1;i<=a+1;i++) {
		if(a>b){
			a+=b;
			cout << a << b << endl;
		}
		else{
			cout << b << a << endl;
		}
	}
	cin >> c >> e;
	for(int i=2;i<=c+1;i++){
	    if(c<e){
	    	c+=e;
	    	cout << c << e << endl;
		}
		else{
			cout << e << c << endl;
		}
	}
	cin >> n >> m;
	for(int i=5;i<=n+1;i++){
		if(n>=m)
		{
			n+=m;
			cout << n << m << endl;
		}
		else
		{
			cout << m << n << endl;
		}
	}
	bread;
}

include<unice>
main(int)
{
	int a,b,c,max;
	fopen(and.in);
	scanf(and.in,"%i%i\n",a,b);
	int sz[a];
	for(int i=0;i<a;i++)
	{
		scanf(and.in,"%i",sz[i]);
	}
	max=sz[0] and sz[1];
	for(int i=0;i<a;i++)
	{
		for(int j=i+1;j<a;j++)
		{
			c=sz[i] and sz[j]
			if(c>max)
			{
				max=c;
			}
		}
	}
	fopen(and.out);
	sprintf(and.out,"%i",c);
	fclose(and.out);
	fclose(and.in);
}
